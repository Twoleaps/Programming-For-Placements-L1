class Node(object):
	"""docstring for Node"""
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right
class BinarySearchTree:
		"""docstring for BinarySearchTree"""
		def __init__(self, root=None):
			self.root = root
		def insert(self, data):
			if self.root:
				current = self root
				while current:
					if data < current.data:
						current = current.left
					elif data > current.right
				current = Node(data)
			else:
				self.root = Node(data)
	bst = BinarySearchTree()
	bst.insert(2)
	bst.insert(1)
	bst.insert(3)
				