#!/bin/python3

import sys

def mass_convert_10_16(file_path):
    left_list = []
    right_list = []
    with open(file_path, "r") as input_file:
        curr_line = input_file.readline()
        while(len(curr_line) > 0):
            # split the line
            halves_str = curr_line.split(' ')
            # convert them into int
            padding = 8 - len(halves_str[0])
            prefix = "0x" + ("0" * padding)
            left_list += [prefix + halves_str[0]]
            padding = 8 - len(halves_str[-1].split('\n')[0])
            prefix = "0x" + ("0" * padding)
            right_list += [prefix + halves_str[-1].split('\n')[0]]
            curr_line = input_file.readline()

    # take care of the left column of data
    with open("./src/puzzle_data/day1/left_data.c","w+") as output_file:
        # Write the start of the array
        output_file.write("const unsigned int left_list[" + str(len(left_list)) + "] __attribute__((aligned(4)))=\n{\n")

        # for readability, truncate each line to 8 16 bit words
        count = 0
        for item in left_list:
            if(count == 0):
                output_file.write("    ")
            output_file.write(item + ', ')
            count += 1
            if(count >= 8):
                output_file.write('\n')
                count = 0
        if(count != 0):
                output_file.write('\n')
        output_file.seek(output_file.tell() - 3)
        output_file.write("\n};")
    
    # take care of the right column of data
    with open("./src/puzzle_data/day1/right_data.c","w") as output_file:
        # Write the start of the array
        output_file.write("const unsigned int right_list[" + str(len(right_list)) + "] __attribute__((aligned(4)))=\n{\n")

        # for readability, truncate each line to 8 16 bit words
        count = 0
        for item in right_list:
            if(count == 0):
                output_file.write("    ")
            output_file.write(item + ', ')
            count += 1
            if(count >= 8):
                output_file.write('\n')
                count = 0
        if(count != 0):
                output_file.write('\n')
        output_file.seek(output_file.tell() - 3)
        output_file.write("\n};")

    # Start creating the header files
    with open("./src/puzzle_data/day1/left_data.h","w") as output_file:
        output_file.write("#ifndef AOC_LEFT_COL\n")
        output_file.write("#define AOC_LEFT_COL\n")
        output_file.write("#define left_list_len " + str(int(len(left_list))) + "\n")
        output_file.write("extern const unsigned int left_list[" + str(len(left_list)) + "];\n")
        output_file.write("#endif")

    with open("./src/puzzle_data/day1/right_data.h","w") as output_file:
        output_file.write("#ifndef AOC_RIGHT_COL\n")
        output_file.write("#define AOC_RIGHT_COL\n")
        output_file.write("#define right_list_len " + str(int(len(right_list))) + "\n")
        output_file.write("extern const unsigned int right_list[" + str(len(right_list)) + "];\n")
        output_file.write("#endif")


if __name__ == "__main__":
    mass_convert_10_16(sys.argv[1])