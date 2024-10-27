class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList():
    def __init__(self):
        self.head = None

    def add(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            node = self.head
            while node.next is not None:
                node = node.next
            node.next = Node(data)

    def delete(self, index):
        if self.head is None:
            print('empty list')
            return
        else:
            count = 0
            node = self.head
            prev = None
            while count != index and node is not None:
                prev = node
                node = node.next
                count += 1
            if count == index:
                if index == 0:
                    self.head = self.head.next
                else:
                    prev.next = node.next
            
            

    def insert(self, data, index):
        if index == 0:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
            return
            
        if self.head is None:
            print('empty list')
            return
        else:
            count = 0
            prev = None
            node = self.head
            while count != index and node is not None:
                prev = node
                node = node.next
                count += 1
            if count == index:
                new_node = Node(data)
                new_node.next = prev.next
                prev.next = new_node

    def print(self):
        if self.head is not None:
            node = self.head
            while node is not None:
                print(node.data)
                node = node.next

    def __print(self, node):
        if node is not None:
            print(node.data)
            self.__print(node.next)

    # Linked List Reversal
    def revert(self):
        last = None
        if self.head is not None:
            node = self.head
            while node is not None:
                tmp = node.next 
                node.next = last
                last = node
                node = tmp
            self.head = last
    
    def print_rec(self):
        self.__print(self.head)