def LCS(A, B):
    m = len(A)
    n = len(B)
    trace = [0] * (m+1)
    for i in range(m + 1):
        trace[i] = [0] * (n+1)
    for i, a in enumerate(A):
        for j, b in enumerate(B):
            if a==b:
                trace[i + 1][j + 1] = trace[i][j] + 1
            else:
                trace[i + 1][j + 1] = max(trace[i][j+1], trace[i+1][j])

    return trace[m][n]

if __name__ == "__main__":
    A = "guurdbaxypvwotateuursrhqnzqeqk"
    B = "qktmyfzeyelbckekldbbhrgbnpzqwo"
    print(LCS(A, B))