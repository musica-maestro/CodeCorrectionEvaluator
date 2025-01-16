import streamlit as st
import random
import os
import pandas as pd
from datetime import datetime
import json

def save_feedback_to_csv(feedback_data, current_file):
    """Save feedback data to a CSV file."""
    # Create feedback directory if it doesn't exist
    os.makedirs("feedback", exist_ok=True)
    csv_path = "feedback/evaluations.csv"
    
    # Prepare the feedback row
    row = {
        'timestamp': datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
        'evaluator': st.session_state.current_user,
        'file': current_file,
        'correctness': feedback_data['correctness'],
        'readability': feedback_data['readability'],
        'efficiency': feedback_data['efficiency'],
        'comments': feedback_data['comments']
    }
    
    # Add hallucination columns
    for issue, value in feedback_data['hallucinations'].items():
        row[f'issue_{issue}'] = value
    
    # Create DataFrame for the new row
    new_row_df = pd.DataFrame([row])
    
    try:
        # Try to read existing CSV
        if os.path.exists(csv_path):
            df = pd.read_csv(csv_path)
            df = pd.concat([df, new_row_df], ignore_index=True)
        else:
            df = new_row_df
        
        # Save to CSV
        df.to_csv(csv_path, index=False)
        return True
    except Exception as e:
        st.error(f"Error saving feedback: {str(e)}")
        return False

def get_next_file():
    """Get the next random file for the current user."""
    if not st.session_state.current_user:
        return None
        
    assets_path = os.path.join("assets", "data_corretti")
    all_files = sorted([f for f in os.listdir(assets_path) if f.endswith('.c')])
    
    # Calculate user's portion of files
    USERS = ["Carla Limongelli", "Daniele Schicchi", "Davide Taibi", "Alessio Ferrato"]
    user_idx = USERS.index(st.session_state.current_user)
    files_per_user = len(all_files) // len(USERS)
    start_idx = user_idx * files_per_user
    end_idx = start_idx + files_per_user if user_idx < len(USERS) - 1 else len(all_files)
    
    user_files = [f for f in all_files[start_idx:end_idx] if f != st.session_state.current_file]
    
    return random.choice(user_files) if user_files else None

def handle_form_submit():
    """Handle form submission and state updates."""
    # Get form data from session state
    feedback_data = {
        "correctness": st.session_state.correctness_slider,
        "readability": st.session_state.readability_slider,
        "efficiency": st.session_state.efficiency_slider,
        "hallucinations": {
            "incorrect_syntax": st.session_state.incorrect_syntax_checkbox,
            "wrong_logic": st.session_state.wrong_logic_checkbox,
            "missing_functionality": st.session_state.missing_functionality_checkbox,
            "extra_functionality": st.session_state.extra_functionality_checkbox,
            "wrong_variable_names": st.session_state.wrong_variable_names_checkbox,
            "wrong_comments": st.session_state.wrong_comments_checkbox
        },
        "comments": st.session_state.comments_textarea
    }
    
    # Save feedback
    if save_feedback_to_csv(feedback_data, st.session_state.current_file):
        next_file = get_next_file()
        if next_file:
            st.session_state.current_file = next_file
            st.rerun()

def render_feedback_section():
    """Render the feedback section with Likert scales and checkboxes."""
    
    if not st.session_state.current_file:
        return None
        
    with st.form(key="feedback_form", clear_on_submit=True):
        # Likert scale questions
        st.subheader("Quality Assessment")
        st.slider(
            "How correct is the LLM's solution?",
            1, 5, 3,
            help="1 = Completely incorrect, 5 = Completely correct",
            key="correctness_slider"
        )
        
        st.slider(
            "How readable is the LLM's code compared to the professor's solution?",
            1, 5, 3,
            help="1 = Much worse, 5 = Much better",
            key="readability_slider"
        )
        
        st.slider(
            "How efficient is the LLM's solution compared to the professor's?",
            1, 5, 3,
            help="1 = Much less efficient, 5 = Much more efficient",
            key="efficiency_slider"
        )
        
        # Hallucination checkboxes
        st.subheader("Hallucinations and Issues")
        st.write("Select any issues found in the LLM's solution:")
        
        st.checkbox("Incorrect syntax", key="incorrect_syntax_checkbox")
        st.checkbox("Wrong logic implementation", key="wrong_logic_checkbox")
        st.checkbox("Missing required functionality", key="missing_functionality_checkbox")
        st.checkbox("Unnecessary extra functionality", key="extra_functionality_checkbox")
        st.checkbox("Incorrect variable naming", key="wrong_variable_names_checkbox")
        st.checkbox("Incorrect or misleading comments", key="wrong_comments_checkbox")
        
        # Additional comments
        st.text_area(
            "Additional Comments",
            height=100,
            key="comments_textarea"
        )
        
        submitted = st.form_submit_button("Submit Feedback", type="primary", on_click=handle_form_submit)
    
    return None 