
def main():
    i = 0
    available = []
    targetTowels = []
    solvable = []
    for line in open("in19.txt", "r").read().splitlines():
        if i == 0:
            available = line.split(", ")
        elif line != "":
            targetTowels.append(line.strip())
        i += 1
    [x.strip() for x in available]
    print(available)
    print(targetTowels)

    cache = {}

    i = 0
    for towel in targetTowels:
        if CanConstruct(towel, available, cache):
            # print(f"Starting towel: {towel}")
            solvable.append(towel)
    
    print(f"Found combinations: {len(solvable)}")


def CanConstruct(pattern: str, available_towels: list[str], cache:dict[str, bool]) -> bool:
    if pattern in available_towels:
        return True
    elif pattern in cache:
        return cache[pattern]
    for towel in available_towels:
        if pattern.startswith(towel):
            rest = pattern[len(towel):]
            if CanConstruct(rest, available_towels, cache):
                cache[pattern] = True
                # print(f"Pattern {towel} fits into {pattern}.")
                return True


if __name__ == "__main__":
    main()