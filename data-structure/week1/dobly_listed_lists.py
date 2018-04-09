def pushBack(key):
	node = new node()
	node.key = key
	node.next = null

	if head = null:
		head = tail = node
		node.prev = null

	else:
		#tail.next = node
		node.prev = tail
		tail = node

def popBack():
	if head == null:
		raise "empty list"

	if head == tail:
		head = tail = null

	tail = tail.prev
	tail.next = null

def addAfter(node, key):
	node2 = new node()
	node2.key = key

	node2.prev = node
	node.next = prev
	node2.next = node.next

	if node2.next != null:
		node2.next.prev = node2

	if tail == node:

	#else:
		tail = node2

def addBefore(node, key):
	node2 = new node()
	node2.key = key

	node2.next = node
	node.prev = node2
	node2.prev = node.prev

	if node2.prev != null:
		node2.prev.next = node2

	if head == node:
	#else:
		head = node2
