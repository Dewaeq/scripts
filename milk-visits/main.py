n, m = [int(x) for x in input().split(' ')]

farms = [x for x in input()]
adj = [set() for _ in range(0, n)]

for _ in range(0, n - 1):
    a, b = [int(x) - 1 for x in input().split(' ')]
    adj[a].add(b)
    adj[b].add(a)


def walk(start, end, cow, found, visited):
    if cow in farms[start]:
        found = True
    if start == end:
        return found
    if len(adj[start]) == 0:
        return False

    result = False

    visited.append(start)
    for f in adj[start]:
        if f not in visited and walk(f, end, cow, found, visited):
            visited.remove(start)
            return True
    visited.remove(start)

    return result


output = ""

for _ in range(0, m):
    a = input().split(' ')
    start, end = [int(x) - 1 for x in a[:2]]
    cow = a[2]

    if walk(start, end, cow, False, []):
        output += "1"
    else:
        output += "0"

print(output)
