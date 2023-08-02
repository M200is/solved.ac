    if(dist[from]==INT_MAX)
                continue;
            if(dist[to]>dist[from]+cost) {
                dist[to]=dist[from]+cost;
                if(i==n)
                    return "YES";
            }