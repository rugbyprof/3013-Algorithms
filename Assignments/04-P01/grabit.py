import re


def find_matches_after_termcolor(text):
    # Define the regex pattern
    pattern = r"(?<=termcolor::)\w+"

    # Find all non-overlapping matches of the pattern in the string
    matches = re.findall(pattern, text)

    return matches


def find_matches_function_names(text):
    # Define the regex pattern
    pattern = r"(?<=std::ostream)\w+"

    # Find all non-overlapping matches of the pattern in the string
    matches = re.findall(pattern, text)

    return matches


# std::ostream& cyan


# Example usage
text = "Some text with termcolor::underline and termcolor::bold among other things."

# with open("main.cpp") as f:
#     file = f.read()


# matches = find_matches_after_termcolor(file)

# matches = sorted(list(set(matches)))

# for match in matches:
#     print(f"#define termcolor::{match} {match.upper()}")

# print(matches)  # Output: ['underline', 'bold']


with open("temp.txt") as f:
    file2 = f.read().split("\n")


defines = []
max = 0
for line in file2:
    parts = line.split()

    choice = parts[1:-1]
    item = choice[0].split("(")[0]
    chunk = len(f"#define {item.upper()}")
    spaces = (25 - chunk) * " "
    print(f"#define {item.upper()} {spaces}termcolor::{item}")

    if chunk > max:
        max = chunk

    defines.append(f"#define {item.upper()} termcolor::{item}")


# for item in defines:
#     items = item.split(" ")


# print(max)

# print(defines)

# for item in defines:
#     parts = item.split()
#     spaces = " " * (max - len(parts[:1]))
#     print(f"{parts[0]} {parts[1]} {spaces} {parts[2]}")
