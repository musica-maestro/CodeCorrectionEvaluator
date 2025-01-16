import streamlit as st
from utils.file_utils import safe_read_file, format_c_code, get_matching_response_file
import os
from components.feedback import render_feedback_section

def render_code_comparison(source_files, responses_path):
    """Render the code comparison section with side-by-side view."""
    if not source_files:
        st.error("No source files found in data_corretti directory")
        return
    
    selected_source = source_files[0]  # Use the first (and only) file
    
    # Load source file
    source_path = os.path.join("assets", "data_corretti", selected_source)
    source_content = safe_read_file(source_path)
    formatted_source = format_c_code(source_content)
    
    # First try to find matching file in Claude responses
    response_files = sorted([f for f in os.listdir(responses_path) if f.endswith('.txt')])
    matching_file = get_matching_response_file(selected_source, response_files)
    
    if matching_file:
        response_path_full = os.path.join(responses_path, matching_file)
        content = safe_read_file(response_path_full)
        formatted_content = format_c_code(content)
    else:
        # If not found in Claude responses, try corretti directory
        corretti_path = os.path.join("assets", "data_corretti")
        corretti_files = sorted([f for f in os.listdir(corretti_path) if f.endswith('.c')])
        matching_file = get_matching_response_file(selected_source, corretti_files)
        
        if matching_file:
            response_path_full = os.path.join(corretti_path, matching_file)
            content = safe_read_file(response_path_full)
            formatted_content = format_c_code(content)
        else:
            st.error("No matching response file found for the selected source file.")
            return
    
    # Create three columns for comparison
    col1, col2, col3 = st.columns(3)
    
    with col1:
        st.subheader("Professor's Solution")
        with st.container(height=600):
            st.code(formatted_source, language='c', line_numbers=True, wrap_lines=True)
    
    with col2:
        st.subheader("LLM's Solution")
        with st.container(height=600):
            st.code(formatted_content, language='c', line_numbers=True, wrap_lines=True)
    
    with col3:
        st.subheader("Feedback")
        with st.container(height=600):
            render_feedback_section() 