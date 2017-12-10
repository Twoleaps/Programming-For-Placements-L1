class Node:
	def __init__(self, data):
		self.data = data # Assign data
		self.next = None # Initialize next as null
class LinkedList:
def __init__(self): 
		self.head = None
def push(self, new_data):
	new_node = Node(new_data)
	new_node.next = self.head
	self.head = new_node