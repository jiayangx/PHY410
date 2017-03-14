class studentrecord:

    score_ = 0.

    def __init__( self, x=[],c=0.):
        self.score_= x


    
    def input(self,l):
        self.score_ = l

    def __add__(self, right ):
        return studentrecord( self.c + right.c)
        
    def average(self, score_):
        c = 0.
        i = 0
        b = len(score_)
        while i < b:
            c = c + score_[i]
            i += 1
            
        d = c / b
        
        return d
