def permutations(n: int) -> int:
    amount = 1
    for i in range(1,n+1):
        amount *= i
    return amount


N = int(input())
if N < 1 or N > 7:
    raise ValueError
else:
    fact = permutations(N)
    print(fact)