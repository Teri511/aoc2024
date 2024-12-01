#!/bin/python3
###############################################################################
# Name: checksum_gen.py
# Desc: Quick script to generate a valid GBA ROM header checksum
# Author: Will Martens
# Credits: GBATEK Manual and Nintendo AGB Programming Manual

import sys

def checksum_gen(header_bytes):
    checksum = 0
    for curr_byte in header_bytes:
        checksum = checksum - curr_byte
    checksum = (checksum - 0x19) & 0xFF
    print("generated checksum: " + str(hex(checksum)))
    return checksum

def header_rebuild(file_path, title_str, title_code_str, maker_code_str):
    if(len(title_str) > 12):
        raise ValueError("Title string must be 12 characters or smaller")
    if(len(title_code_str) != 4):
        raise ValueError("Title code string must be exactly 4 characters")
    if(len(maker_code_str) != 2):
        raise ValueError("Maker code string must be exactly 2 characters")

    with open(file_path, "r+b") as gba_rom:
        gba_rom.seek(0xA0)
        # write the game title, 12 bytes
        padding = bytes(12 - len(title_str))
        title_bytes = str.encode(title_str) + padding
        gba_rom.write(title_bytes)
        # write the game code, 4 bytes
        gba_rom.write(str.encode(title_code_str))
        # write the maker code, 2 bytes
        gba_rom.write(str.encode(maker_code_str))


        # Seek back to the start and get ready to write the checksum
        gba_rom.seek(0xA0)
        bytes_to_checksum = gba_rom.read(0x1D)
        # bytes_to_checksum now contains all bytes from hex 0x00A0 to hex
        # 0x00BC in the given GBA ROM.
        checksum_val_byte = checksum_gen(bytes_to_checksum)
        gba_rom.seek(0xBD)
        gba_rom.write(checksum_val_byte.to_bytes(1, 'big'))

if __name__ == "__main__":
    header_rebuild(sys.argv[1], sys.argv[2],sys.argv[3],sys.argv[4])