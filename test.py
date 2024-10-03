import subprocess
import os
import pytest

# Path to the C programs
MY_FILE_READ = './myFileRead'
MY_FILE_WRITE = './myFileWrite'
MY_FILE_OPERATIONS = './myFileOperations'
TEST_FILE = 'test.txt'
OUTPUT_FILE = 'output.txt'


@pytest.fixture
def setup_test_file():
    """Fixture to create a test file before running tests."""
    with open(TEST_FILE, 'w') as f:
        f.write("This is a test file.\nWith multiple lines.\nAnd words.")
    yield
    # Cleanup the test file after tests
    os.remove(TEST_FILE)


@pytest.fixture
def setup_output_file():
    """Fixture to ensure output file is deleted after writing tests."""
    yield
    if os.path.exists(OUTPUT_FILE):
        os.remove(OUTPUT_FILE)


def run_program(program, input_text=None):
    """Helper function to run the C program and capture its output."""
    try:
        if input_text:
            process = subprocess.run([program], input=input_text, text=True, capture_output=True)
        else:
            process = subprocess.run([program], capture_output=True)
        return process.stdout.strip(), process.stderr.strip(), process.returncode
    except FileNotFoundError:
        pytest.fail(f"Program {program} not found or not executable.")


def test_file_read(setup_test_file):
    """Test if the myFileRead program reads the file content correctly."""
    output, error, returncode = run_program(MY_FILE_READ)
    assert returncode == 0, f"Program returned error: {error}"
    assert "This is a test file." in output, "Program did not correctly read file content."
    assert "With multiple lines." in output, "Program did not correctly read file content."


def test_file_write(setup_output_file):
    """Test if the myFileWrite program writes user input to a file."""
    user_input = "Hello, this is a test input.\n"
    output, error, returncode = run_program(MY_FILE_WRITE, input_text=user_input)
    assert returncode == 0, f"Program returned error: {error}"

    # Check if the file was written correctly
    with open(OUTPUT_FILE, 'r') as f:
        content = f.read()
    assert user_input.strip() in content, "File was not written correctly."


def test_file_operations(setup_test_file, setup_output_file):
    """Test if the myFileOperations program reads and appends to the file correctly."""
    output, error, returncode = run_program(MY_FILE_OPERATIONS)
    assert returncode == 0, f"Program returned error: {error}"

    # Check if the file was updated with new content
    with open(TEST_FILE, 'r') as f:
        content = f.read()
    assert "This is a test file." in content, "Original file content missing."
    assert "Appended text" in content, "New content not appended correctly."

