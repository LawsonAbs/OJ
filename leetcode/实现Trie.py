max_row = 10000
class Trie:
    def __init__(self):
        self.tot = 0 
        self.trie = [ [0] * 26 for i in range(max_row)]        
        self.end = [0] * max_row # 结束标记

    def insert(self, word: str) -> None:
        p = 0 # 每次重置为0
        for i in word:
            idx = ord(i) - 97
            if self.trie[p][idx] == 0:
                self.tot += 1
                self.trie[p][idx] = self.tot            
            p = self.trie[p][idx]
        self.end[p] = 1


    def search(self, word: str) -> bool:
        p = 0 # 每次重置为0
        for i in word:
            idx = ord(i) - 97
            if self.trie[p][idx] == 0:
                return False
            else:
                p = self.trie[p][idx]
        if self.end[p] == 1:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        p = 0 # 每次重置为0
        for i in prefix:
            idx = ord(i) - 97
            if self.trie[p][idx] == 0:
                return False
            else:
                p = self.trie[p][idx]
        if self.end[p] == 0:
            return True
        return False
        
# Your Trie object will be instantiated and called as such:
obj = Trie()
# words = ["lg","dawn","session","lawson"] 
words = ["a"]
for word in words:
    obj.insert(word)

print("...搜索字符串...")
# words =["daw","lawson"]
words = ["a"]
for word in words:
    param_2 = obj.search(word)
    print(param_2)

print("...测试前缀...")
# prefixs = ["l","law"]
prefixs = ["a"]
for prefix in prefixs:
    param_3 = obj.startsWith(prefix)
    print(param_3)

