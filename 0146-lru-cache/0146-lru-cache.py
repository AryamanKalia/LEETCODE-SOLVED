
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key in self.cache:
            node = self.cache[key]
            self._move_to_front(node)
            return node.value
        return -1

    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self._move_to_front(node)
        else:
            if len(self.cache) >= self.capacity:
                self._remove_last()
            node = Node(key, value)
            self.cache[key] = node
            self._add_to_front(node)

    def _move_to_front(self, node):
        if node == self.head:
            return
        self._remove_node(node)
        self._add_to_front(node)

    def _remove_node(self, node):
        if node.prev:
            node.prev.next = node.next
        if node.next:
            node.next.prev = node.prev
        if node == self.head:
            self.head = node.next
        if node == self.tail:
            self.tail = node.prev

    def _add_to_front(self, node):
        if self.head:
            self.head.prev = node
        node.next = self.head
        node.prev = None
        self.head = node
        if not self.tail:
            self.tail = node

    def _remove_last(self):
        if self.tail:
            del self.cache[self.tail.key]
            if self.tail.prev:
                self.tail.prev.next = None
            self.tail = self.tail.prev
        if not self.tail:
            self.head = None
