def add_separator_on_empty_line(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            outfile.write(line)
            if line.strip() == '':
                outfile.write('---\n')

add_separator_on_empty_line('D:/Programming/C++/ASCII animation/ascii-animation.txt', 'D:/Programming/C++/ASCII animation/output/ascii-animation-spt.txt')
