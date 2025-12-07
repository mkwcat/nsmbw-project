import os, re as regex

lwz_r13 = regex.compile(r"^(.*(?:lbz|lhz|lha|lwz|stb|sth|stw|lfs|lfd|stfs|stfd)\s+r[0-9]+,\s*)(-?[0-9]+)\((r13|r2)\)(.*$)")
addi_r13 = regex.compile(r"^(.*)(addi|subi)(\s+r[0-9]+,\s*)(r13|r2),\s*(-?[0-9]+)(.*$)")

# search for r13 usage in all .cpp files in the source recursively

r13_addr = 0x8042F980
r2_addr = 0x80433360

for root, dirs, files in os.walk("../source"):
    for file in files:
        if file.endswith(".cpp"):
            modified = False
            with open(os.path.join(root, file), 'r') as f:
                lines = f.readlines()
            for i, line in enumerate(lines):
                m = addi_r13.match(line)
                if not m:
                    continue

                print(m.groups())

                offset = int(m.group(5))
                if (m.group(2) == "subi"):
                    offset = -offset

                reg = m.group(4)
                if (reg == "r13"):
                    reg_addr = r13_addr
                elif (reg == "r2"):
                    reg_addr = r2_addr
                else:
                    throw("Invalid register")

                address = 'UNDEF_' + hex(reg_addr + offset)[2:]

                new_line = m.group(1) + "la  " + m.group(3) + address + '@sda21' + m.group(6) + '\n'
                print(new_line)
                lines[i] = new_line
                modified = True

            if modified:
                with open(os.path.join(root, file), 'w') as f:
                    f.writelines(lines)