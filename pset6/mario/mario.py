def main(n):
    assert n in range(1,24)
    for i in range(2,n+2):
        print (' '*(n+1-i), end='')
        print ('#'*i)

if __name__ == '__main__':
    while True:
        lines = int(input('Height: ').strip())
        if lines in range(1,24):
            break
    main(lines)