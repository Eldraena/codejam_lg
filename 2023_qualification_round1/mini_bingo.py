import sys
from itertools import permutations

def get_score(grid_mark, i, j):
    score = 0

    flag_fail = False
    for k in range(3):
        if not grid_mark[i][k]:
            flag_fail = True
            break
    if not flag_fail:
        score += 1

    flag_fail = False
    for k in range(3):
        if not grid_mark[k][j]:
            flag_fail = True
            break
    if not flag_fail:
        score += 1

    if i == j:
        flag_fail = False
        for k in range(3):
            if not grid_mark[k][k]:
                flag_fail = True
                break
        if not flag_fail:
            score += 1

    if i == 2 - j:
        flag_fail = False
        for k in range(3):
            if not grid_mark[k][2 - k]:
                flag_fail = True
                break
        if not flag_fail:
            score += 1

    return score

def solve():
    str_score = ""
    seed_str = sys.stdin.readline().strip()
    grid_letter = [sys.stdin.readline().strip() for _ in range(3)]
    grid_mark = [[False for i in range(3)] for _ in range(3)]

    position = dict()
    for i in range(3):
        for j in range(3):
            position[grid_letter[i][j]] = (i,j)

    for c in seed_str:
        i,j = position[c]
        grid_mark[i][j] = True
        score = get_score(grid_mark, i, j)
        str_score += str(score)

    sort_str = sorted(seed_str)
    for permutation_str in permutations(sort_str, 9):
        grid_mark = [[False for i in range(3)] for _ in range(3)]
        flag_failed = False
        for idx, c in enumerate(permutation_str):
            i, j = position[c]
            grid_mark[i][j] = True
            score = get_score(grid_mark, i, j)
            if score != int(str_score[idx]):
                flag_failed = True
                break
        if flag_failed == False:
            lexico_str = "".join(permutation_str)
            break

    print(str_score, lexico_str)


    

num_tc = int(sys.stdin.readline().strip())
for _ in range(num_tc):
    solve()