#!/usr/bin/python3
"""This module contains the function validUTF8"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    """
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    for byte in data:
        # Check if the most significant bit (MSB) is set
        if num_bytes == 0:
            # Count the number of leading ones in the byte
            mask = 1 << 7
            while mask & byte:
                num_bytes += 1
                mask >>= 1

            # A single byte character
            if num_bytes == 0:
                continue

            # Invalid UTF-8 character
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # Check if the byte is a valid continuation byte
            if byte >> 6 != 0b10:
                return False

        # Decrement the number of remaining bytes to process
        num_bytes -= 1

    # If there are remaining bytes, it means an incomplete character
    return num_bytes == 0
