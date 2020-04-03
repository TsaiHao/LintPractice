import os
import re

if __name__ == "__main__":
    print(os.getcwd())
    os.chdir("./LintCodes/LeetCode")
    fs = os.listdir()
    pat = "(\d+)(\w+.cpp)"
    print(len(fs))

    for f in fs:
        matchObj = re.match(pat, f)
        if matchObj:
            nth = int(matchObj.group(1))
            newName = "{:04d}".format(nth) + matchObj.group(2)
            os.rename(f, newName)
            