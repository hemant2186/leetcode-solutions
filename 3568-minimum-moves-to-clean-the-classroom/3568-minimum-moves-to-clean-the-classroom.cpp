class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        if (fullMask == 0)
            return 0;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << litterCount, -1))
        );

        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int moves = 0;

        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << litterId[nr][nc]);
                    }

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (nmask == fullMask)
                        return moves + 1;
                        
                    if (ne <= best[nr][nc][nmask])
                        continue;

                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            ++moves;
        }

        return -1;
    }
};