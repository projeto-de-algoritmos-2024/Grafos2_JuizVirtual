import heapq

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # vao servir de contador para determinar quando parar o algoritmo
        linhas, colunas = len(grid), len(grid[0])
        # criando os movimentos possiveis: direita, esquerda, baixo, cima
        direcao = [[1,0],[-1,0],[0,1],[0,-1]]
        # criando o heap para salvar o caminho feito
        travessia = [(grid[0][0],0,0)]
        # lista para guardar o caminho feito na matriz iniciado com a posicao inicial (0,0)
        visitado = set()
        visitado.add((0,0))

        # primeiro check para progredir o algoritmo, se a travessia nao for possivel, encerra o algoritmo
        if grid[0][1] > 1 and grid[1][0] > 1 :
            return -1
        
        while travessia :
            # tira a primeira posicao do heap e checa se chegou ao final do algoritmo
            tempo, l, c = heapq.heappop(travessia)
            if l == linhas - 1 and c == colunas -1 :
                return tempo
            # loop para checar os vizinhos
            for dl,dc in direcao : # direcoes possiveis(linha ou coluna)
                pl = l + pl # proximo espaco possivel(linha ou coluna)
                pc = c + pc 
                # checa qual o proximo espaco da matriz que podemos acessar
                if 0 <= pl < linhas and 0 <= pc < colunas and (pl,pc) not in visitado:
                    # adiciona o espaco acessado a lista de visitados para evitar passos extras
                    visitado.add((pl,pc))
                    if grid[pl][pc] <= tempo + 1:
                        heapq.heappush(travessia,[tempo+1,pl,pc])
                    else:
                        if(grid[pl][pc] - tempo) % 2 == 0:
                            heapq.heappush(travessia,[grid[pl][pc]+1,pl,pc])
                        else:
                            heapq.heappush(travessia, [grid[pl][pc],pl,pc])
        return -1