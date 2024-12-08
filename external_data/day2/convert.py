#!/bin/python3
# NOTE: nothing goes over 99, so 1 byte per entry can work here

import sys

def convert_reports(file_path):
    line_list = []
    with open(file_path, "r") as input_file:
        curr_line = input_file.readline()
        while(len(curr_line) > 0):
            split_str = curr_line.split('\n')[0].split(' ')
            # Add a null terminator
            line_list += split_str + ["0"]
            curr_line = input_file.readline()
    # at this point, we now have a list of null terminated ints
    with open("./src/puzzle_data/day2/data.c","w+") as output_file:
        output_file.write("const unsigned char day2_data[" + str(len(line_list)) + "] __attribute__((aligned(4)))=\n{\n")
        count = 0
        for item in line_list:
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
    
    with open("./src/puzzle_data/day2/data.h","w") as output_file:
        output_file.write("#ifndef AOC_DAY2\n")
        output_file.write("#define AOC_DAY2\n")
        output_file.write("#define day2_len " + str(int(len(line_list))) + "\n")
        output_file.write("extern const unsigned int day2_data[" + str(len(line_list)) + "];\n")
        output_file.write("#endif")

if __name__ == "__main__":
    convert_reports(sys.argv[1])