class Node:
    def __init__(self,value = 0):
        self.value = value
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = None

    def get(self, index: int) -> int:
        if index == 0:
            if self.head:
                return self.head.value
            return -1
        else:
            temp = self.head
            ind = index
            for _ in range(index):
                if not temp:
                    return -1
                temp = temp.next
            if not temp:
                return -1
            return temp.value

    def addAtHead(self, val: int) -> None:
        newNode = Node(val)
        newNode.next = self.head
        self.head = newNode
        

    def addAtTail(self, val: int) -> None:
        temp = self.head
        if not temp:
            temp = Node(val)
            self.head = temp
            return
        while temp and temp.next != None:
            temp = temp.next
        newNode = Node(val)
        temp.next = newNode

    def addAtIndex(self, index: int, val: int) -> None:
        newNode = Node(val)
        if index == 0:
            newNode.next = self.head
            self.head = newNode
            return
        temp = self.head
        for i in range(index - 1):
            if not temp:
                return
            temp = temp.next
        if not temp:
            return
        newNode.next = temp.next
        temp.next = newNode

    def deleteAtIndex(self, index: int) -> None:
        if index == 0:
            if self.head:
                self.head = self.head.next
            return
        temp = self.head
        for i in range(index - 1):
            if not temp or not temp.next:
                return 
            temp = temp.next
        if temp and temp.next:
            temp.next = temp.next.next



# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)