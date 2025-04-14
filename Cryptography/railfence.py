def display_matrix(matrix):
    for row in matrix:
        print(' '.join([str(cell) if cell is not None else '.' for cell in row]))
def rail_fence(plain_text, key, encrypt=True):
    matrix = [[None for _ in range(len(plain_text))] for _ in range(key)]
    row, col = 0, 0
    move_down = True  # Direction flag for row movement
    position = []  
    for char in plain_text:
        position.append((row, col))
        col += 1  # Move to the next column
        if row == 0:
            move_down = True
        elif row == key - 1:
            move_down = False
        if move_down:
            row += 1
        else:
            row -= 1
    result = ""
    if encrypt:  # If encrypting, fill the matrix with plain_text characters
        for i in range(len(plain_text)):
            for pos in position:
                x, y = pos
                if y == i:
                    matrix[x][y] = plain_text[i]

        display_matrix(matrix)  # Display matrix for visual understanding
        # Read off the matrix row by row to get the encrypted result
        for i in range(len(plain_text)):
            for pos in position:
                x, y = pos
                if x == i:
                    result += matrix[x][y]
    else:  # If decrypting, fill the matrix with the encrypted text
        count = 0
        for i in range(len(plain_text)):
            for pos in position:
                x, y = pos
                if x == i:
                    matrix[x][y] = plain_text[count]
                    count += 1
        display_matrix(matrix)  
        for i in range(len(plain_text)):
            for pos in position:
                x, y = pos
                if y == i:
                    result += matrix[x][y]

    return result
def main():
    plain_text = "BHUCHAL".upper()  # Predefined text
    key = 2 
    encrypted_text = rail_fence(plain_text, key, encrypt=True)
    print("Encrypted text: ", encrypted_text)
    decrypted_text = rail_fence(encrypted_text, key, encrypt=False)
    print("Decrypted text:", decrypted_text)

if __name__ == "__main__":
    main()
