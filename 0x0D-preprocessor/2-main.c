import os

def print_filename():
    filename = os.path.basename(__file__)
    print(filename)

print_filename()
