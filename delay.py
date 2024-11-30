import collections
import heapq # ja implementa um minheap.

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # guarda os caminhos 
        caminhos = collections.defaultdict(list)
        # criando o grafo dos caminhos possiveis para a implementacao da rede
        for u,v,w in times:
            caminhos[u].append((v,w))
        
        # heap minimo para manter o custo das arestas, que e o tempo para chegar aos nos adjascentes
        delay = [(0,k)]
        # cria uma lista do tipo set que ira salvar os nos ja visitados para evitar loops
        visitado = set()
        # valor a ser retornado para a funcao, pois ira fazer a soma dos custos para dar o tempo de delay
        tempo = 0

        while delay:
            # tira o no de inicio para fazer a travessia no grafo
            w1,n1 = heapq.heappop(delay)
            # evita a ocorrencia de loops
            if n1 in visitado :
                continue
            visitado.add(n1)
            # max vai retornar o maior valor entre os dois passados para ela e salvar, que sera o valor da travessia
            tempo = max(tempo,w1)
            # checa o valor dos vizinhos e adiciona o valor do delay ao tempo
            for n2,w2 in caminhos[n1]:
                if n2 not in visitado:
                    heapq.heappush(delay, (w2, n2))
        # retorna o tempo para atravessar todo o grafo caso a lista de visitados atinja o valor igual ao entregue na funcao n,
        # do contrario, retorna -1
        return tempo if len(visitado) == n else -1
                    
