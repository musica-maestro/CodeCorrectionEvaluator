import chardet
import re

def safe_read_file(file_path):
    """Safely read file content trying different encodings."""
    # First try to detect the encoding
    with open(file_path, 'rb') as file:
        raw_data = file.read()
        detected = chardet.detect(raw_data)
        encoding = detected['encoding']
    
    # Try the detected encoding first
    try:
        with open(file_path, 'r', encoding=encoding) as file:
            return file.read()
    except:
        # If that fails, try common encodings
        encodings = ['utf-8', 'latin-1', 'iso-8859-1', 'cp1252']
        for enc in encodings:
            try:
                with open(file_path, 'r', encoding=enc) as file:
                    return file.read()
            except:
                continue
        # If all fails, use latin-1 as it can read any byte stream
        with open(file_path, 'r', encoding='latin-1') as file:
            return file.read()

def format_c_code(code):
    """Format C code with proper indentation and fix common issues."""
    # Fix common formatting issues
    code = re.sub(r'/\*\s*', '/* ', code)  # Fix comment start spacing
    code = re.sub(r'\s*\*/', ' */', code)  # Fix comment end spacing
    
    # Split into lines and process each line
    lines = code.split('\n')
    formatted_lines = []
    indent_level = 0
    in_multiline_comment = False
    
    for line in lines:
        # Remove leading/trailing whitespace
        stripped_line = line.strip()
        
        if not stripped_line:
            formatted_lines.append('')
            continue
            
        # Handle multiline comments
        if '/*' in stripped_line and '*/' not in stripped_line:
            in_multiline_comment = True
        elif '*/' in stripped_line:
            in_multiline_comment = False
            
        # Calculate indentation changes
        if '}' in stripped_line and not stripped_line.startswith('else'):
            indent_level = max(0, indent_level - 1)
            
        # Special handling for else statements
        if stripped_line.startswith('else'):
            indent_level = max(0, indent_level - 1)
            
        # Apply indentation
        if in_multiline_comment:
            formatted_lines.append('    ' * indent_level + stripped_line)
        else:
            # Handle one-liners with braces
            if '{' in stripped_line and '}' in stripped_line:
                formatted_lines.append('    ' * indent_level + stripped_line)
            else:
                formatted_lines.append('    ' * indent_level + stripped_line)
                
        # Update indent level for next line
        if '{' in stripped_line and '}' not in stripped_line:
            indent_level += 1
        elif stripped_line.endswith('{'):
            indent_level += 1
            
        # Handle else statements
        if stripped_line.startswith('else'):
            indent_level += 1
    
    return '\n'.join(formatted_lines)

def get_matching_response_file(source_file, response_files):
    """Match source file with corresponding response file based on ID and type."""
    # Extract components from source file (e.g., "21_001_A_ricorsione.c")
    source_parts = source_file.split('_')
    if len(source_parts) < 3:
        return None
    
    year = source_parts[0]  # "21"
    number = source_parts[1]  # "001"
    letter = source_parts[2]  # "A"
    exercise_type = source_parts[3].split('.')[0]  # "ricorsione"
    
    # Look for matching response file (e.g., "21_ricorsione_001_A.txt" or "21_001_A_ricorsione.c")
    patterns = [
        f"{year}_{exercise_type}_{number}_{letter}.txt",  # Claude response format
        f"{year}_{number}_{letter}_{exercise_type}.c"     # Corretti format
    ]
    
    for pattern in patterns:
        matches = [f for f in response_files if f.lower() == pattern.lower()]
        if matches:
            return matches[0]
    
    return None 