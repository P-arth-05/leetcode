from typing import List
import heapq

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        graph = [[] for _ in range(n)]

        lo = float("inf")
        hi = 0

        for u, v, w in edges:
            # Skip edges incident to offline intermediate nodes
            if (u != 0 and u != n - 1 and not online[u]) or \
               (v != 0 and v != n - 1 and not online[v]):
                continue

            graph[u].append((v, w))
            lo = min(lo, w)
            hi = max(hi, w)

        if lo == float("inf"):
            return -1

        def check(limit):
            INF = 10 ** 30
            dist = [INF] * n
            dist[0] = 0

            pq = [(0, 0)]

            while pq:
                d, u = heapq.heappop(pq)

                if d != dist[u]:
                    continue

                if d > k:
                    continue

                for v, w in graph[u]:
                    if w < limit:
                        continue

                    nd = d + w

                    if nd < dist[v]:
                        dist[v] = nd
                        heapq.heappush(pq, (nd, v))

            return dist[n - 1] <= k

        if not check(lo):
            return -1

        ans = lo

        while lo <= hi:
            mid = (lo + hi) // 2

            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans