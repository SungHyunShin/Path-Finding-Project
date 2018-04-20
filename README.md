Project 05: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

3. 
| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.002998 sec  | 1.207031 Mb    |
| 20            | 0.007997 sec  | 1.230469 Mb    |
| 50            | 0.042993 sec  | 1.371094 Mb    |
| 100           | 0.184971 sec  | 1.875000 Mb    |
| 200           | 0.802877 sec  | 3.832031 Mb    |
| 500           | 5.739127 sec  | 17.511719 Mb   |
| 1000          | 24.934210 sec | 66.253906 Mb   |
|---------------|---------------|----------------|

for 1000
24.956205 seconds	66.250000 Mbytes
24.934210 seconds	66.253906 Mbytes
24.657249 seconds	66.250000 Mbytes
