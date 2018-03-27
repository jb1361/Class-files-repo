
import heapq

class Node:
    def __init__(self, state=None, parent=None, cost=0, depth=0, children=[]):
        self.state = state
        self.parent = parent
        self.cost = cost
        self.depth = depth
        self.children = children

    def is_goal(self, goal_state):
        return is_goal_state(self.state, goal_state)

    def expand(self):
        new_states = operator(self.state)
        self.children = []
        for state in new_states:
            self.children.append(Node(state, self, self.cost + 1, self.depth + 1))

    def parents(self):
        current_node = self
        while current_node.parent:
            yield current_node.parent
            current_node = current_node.parent

    def gn(self):
        costs = self.cost
        for parent in self.parents():
            costs += parent.cost

        return costs


		
#best first search 
def bfsSearch(state, goal_state, fn):
    """Best-first search"""
    queue = []
    entrance = 0
    node = Node(state)
    while not node.is_goal(goal_state):
        node.expand()
        for child in node.children:
            queue_item = (fn(child), entrance, child)
            heapq.heappush(queue, queue_item)
            entrance += 1
        node = heapq.heappop(queue)[2]

    output = []
    output.append(node.state)
    for parent in node.parents():
        output.append(parent.state)
    output.reverse()

    return output
	
#===============	
			

from copy import deepcopy


def is_goal_state(state, goal_state):
    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] != goal_state[i][j]:
                return False
    return True


def operator(state):
    states = []

    zero_i = None
    zero_j = None

    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] == 0:
                zero_i = i
                zero_j = j
                break

    def add_swap(i, j):
        new_state = deepcopy(state)
        new_state[i][j], new_state[zero_i][zero_j] = new_state[zero_i][zero_j], new_state[i][j]
        states.append(new_state)

    if zero_i != 0:
        add_swap(zero_i - 1, zero_j)

    if zero_j != 0:
        add_swap(zero_i, zero_j - 1)

    if zero_i != len(state) - 1:
        add_swap(zero_i + 1, zero_j)

    if zero_j != len(state) - 1:
        add_swap(zero_i, zero_j + 1)

    return states

	

def search(state, goal_state):

    def gn(node):
        return node.gn()

    tiles_places = []
    for i in range(len(goal_state)):
        for j in range(len(goal_state)):
            heapq.heappush(tiles_places, (goal_state[i][j], (i, j)))

    def hn(node):
        cost = 0
        for i in range(len(node.state)):
            for j in range(len(node.state)):
                tile_i, tile_j = tiles_places[node.state[i][j]][1]
                if i != tile_i or j != tile_j:
                    cost += abs(tile_i - i) + abs(tile_j - j)
        return cost

    def fn(node):
        return gn(node) + hn(node)

    return bfsSearch(state, goal_state, fn)
	

	
	
initial_state = [1,2,3,4]
initial_state[0] = [1,2,3,4]
initial_state[1] = [5,6,7,8]
initial_state[2] = [9,10,11,12]
initial_state[3] = [13,14,15]
print(initial_state)
goal_state = [[1,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]]
search(initial_state,goal_state)
	
