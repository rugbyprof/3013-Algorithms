

def md_table():
    for i in range(26):
        print(f" |",end="")

    print("")

    for i in range(26):
        print(f"|:----:",end="")

    print("")

    for i in range(26):
        print(f"{chr(i+65)} |",end="")

    print("")

    for i in range(26):
        print(f"{i+65} |",end="")

    print("")

    for i in range(26):
        print(f"{chr(i+97)} |",end="")

    print("")

    for i in range(26):
        print(f"{i+97} |",end="")

    print("")

def html_table():
    print("<table>")
    print("<tr>")
    for i in range(26):
        print(f"<td>{chr(i+65)}</td>",end="")

    print("</tr>")
    print("<tr>")

    for i in range(26):
        print(f"<td>{i+65}</td>",end="")

    print("</tr>")
    print("</table>")


    print("<table>")
    print("<tr>")
    for i in range(26):
        print(f"<td>{chr(i+97)}</td>",end="")

    print("</tr>")
    print("<tr>")

    for i in range(26):
        print(f"<td>{i+97}</td>",end="")

    print("</tr>")
    print("</table>")

html_table()