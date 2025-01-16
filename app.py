import streamlit as st
import os
import random
import pandas as pd
import json
from components.code_comparison import render_code_comparison
from components.feedback import render_feedback_section

st.set_page_config(layout="wide")

# User list for even distribution
USERS = ["Carla Limongelli", "Daniele Schicchi", "Davide Taibi", "Alessio Ferrato"]

# Initialize session state variables
if 'current_user' not in st.session_state:
    st.session_state.current_user = None
if 'current_file' not in st.session_state:
    st.session_state.current_file = None
if 'feedback_results' not in st.session_state:
    st.session_state.feedback_results = {}
if 'needs_rerun' not in st.session_state:
    st.session_state.needs_rerun = False
if 'show_text_criteria' not in st.session_state:
    st.session_state.show_text_criteria = False

# Function to get number of evaluations for a user
def get_user_evaluations(username):
    csv_path = "feedback/evaluations.csv"
    if os.path.exists(csv_path):
        df = pd.read_csv(csv_path)
        return len(df[df['evaluator'] == username])
    return 0

# Function to reset user data
def reset_user_data():
    if st.session_state.current_user:
        # Clear evaluations for current user from CSV
        csv_path = "feedback/evaluations.csv"
        if os.path.exists(csv_path):
            df = pd.read_csv(csv_path)
            # Keep only rows from other users
            df = df[df['evaluator'] != st.session_state.current_user]
            if len(df) > 0:
                df.to_csv(csv_path, index=False)
            else:
                # If no rows left, delete the file
                os.remove(csv_path)
        
        st.session_state.needs_rerun = True

def toggle_text_criteria():
    st.session_state.show_text_criteria = not st.session_state.show_text_criteria

def show_text_and_criteria():
    if not st.session_state.current_file:
        return
    
    # Extract the exercise type and number from the filename
    # Example: 21_001_A_ricorsione.c -> 21_ricorsione_A
    parts = st.session_state.current_file.split('_')
    year = parts[0]
    exercise_type = parts[3].replace('.c', '')
    letter = parts[2]
    
    text_file = f"testo_{year}_{exercise_type}_{letter}.txt"
    criteria_file = f"criteri_{year}_{exercise_type}_{letter}.txt"
    
    text_path = os.path.join("assets", "testi_criteri", text_file)
    criteria_path = os.path.join("assets", "testi_criteri", criteria_file)
    
    if os.path.exists(text_path):
        with open(text_path, 'r') as f:
            text_content = f.read()
    else:
        text_content = "Text file not found"
        
    if os.path.exists(criteria_path):
        with open(criteria_path, 'r') as f:
            criteria_content = f.read()
    else:
        criteria_content = "Criteria file not found"
    
    with st.container():
        st.markdown("""
        <style>
        .overlay-card {
            background-color: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            margin-bottom: 20px;
        }
        </style>
        """, unsafe_allow_html=True)
        
        col1, col2 = st.columns(2)
        with col1:
            with st.container(height=600):
                st.markdown("### Exercise Text")
                st.code(text_content, language=None, wrap_lines=True)
            
        with col2:
            with st.container(height=600):
                st.markdown("### Evaluation Criteria")
                st.code(criteria_content, language=None, wrap_lines=True)
        
        if st.button("Close", key="close_text_criteria"):
            st.session_state.show_text_criteria = False
            st.rerun()

# Check if we need to rerun
if st.session_state.needs_rerun:
    st.session_state.needs_rerun = False
    st.rerun()

col1, col2 = st.columns([3, 1])
with col1:
    selected_name = st.selectbox(
        "Select your name",
        options=["Select a name...", *USERS],
        index=0
    )
with col2:
    col2_1, col2_2, col2_3, col2_4 = st.columns([1, 1, 1, 1])
    with col2_1:
        if selected_name != "Select a name...":
            st.metric("Files evaluated", get_user_evaluations(selected_name))
    with col2_2:
        if selected_name != "Select a name...":
            # Read from the feedback CSV file
            csv_path = "feedback/evaluations.csv"
            if os.path.exists(csv_path):
                df = pd.read_csv(csv_path)
                # Filter for current user
                user_df = df[df['evaluator'] == selected_name]
                if not user_df.empty:
                    csv = user_df.to_csv(index=False).encode('utf-8')
                    st.download_button(
                        label="📥",
                        data=csv,
                        file_name=f'evaluation_results_{selected_name}.csv',
                        mime='text/csv',
                    )
                else:
                    st.write("No evaluations yet")
            else:
                st.write("No evaluations yet")
    with col2_3:
        if selected_name != "Select a name...":
            st.button("🔄 Reset", on_click=reset_user_data, help="Reset evaluation counter for current user")
    with col2_4:
        if selected_name != "Select a name...":
            st.button("📝 Text & Criteria", on_click=toggle_text_criteria, help="Show exercise text and evaluation criteria")

    if selected_name != st.session_state.current_user:
        st.session_state.current_user = selected_name
        
        if selected_name != "Select a name...":
            # Get all available files for the user
            assets_path = os.path.join("assets", "data_corretti")
            all_files = sorted([f for f in os.listdir(assets_path) if f.endswith('.c')])
            
            # Calculate user's portion of files
            user_idx = USERS.index(selected_name)
            files_per_user = len(all_files) // len(USERS)
            start_idx = user_idx * files_per_user
            end_idx = start_idx + files_per_user if user_idx < len(USERS) - 1 else len(all_files)
            
            user_files = all_files[start_idx:end_idx]
            
            if user_files:
                st.session_state.current_file = random.choice(user_files)
            else:
                st.session_state.current_file = None
                st.warning("No files available for review.")
        else:
            st.session_state.current_file = None

    if selected_name != "Select a name...":
        st.write(f"Current file: {st.session_state.current_file}")

if not st.session_state.current_user:
    st.warning("Please select your name to continue.")
    st.stop()

# Show text and criteria if enabled
if st.session_state.show_text_criteria:
    show_text_and_criteria()

# Add Tailwind-inspired CSS
st.markdown("""
<style>
    /* Base styles */
    .stTabs [data-baseweb="tab-panel"] {
        @apply pt-4;
    }
    
    .stTabs [data-baseweb="tab-list"] {
        @apply gap-2;
    }
    
    .stTabs [data-baseweb="tab"] {
        @apply h-12 whitespace-pre-wrap bg-gray-100 rounded px-4 py-2;
    }
    
    .stTabs [aria-selected="true"] {
        @apply bg-gray-200;
    }

    /* Layout */
    .stHorizontalBlock {
        @apply gap-8;
    }
    
    /* Code blocks */
    .stCodeBlock {
        max-height: 600px;
        overflow-y: auto !important;
    }

    /* Scrollbar styling */
    .stCodeBlock::-webkit-scrollbar {
        width: 8px;
        height: 8px;
    }

    .stCodeBlock::-webkit-scrollbar-track {
        @apply bg-gray-100 rounded;
    }

    .stCodeBlock::-webkit-scrollbar-thumb {
        @apply bg-gray-300 rounded hover:bg-gray-400;
    }
</style>
""", unsafe_allow_html=True)

responses_path = os.path.join("assets", "claude-3.5-sonnet-2024-11-20_14_jan")

# Render the code comparison section with current file
if st.session_state.current_file:
    render_code_comparison([st.session_state.current_file], responses_path)
else:
    st.warning("Please select a name to view code comparison.")
