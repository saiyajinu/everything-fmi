data Point = Pt [Int]
   deriving Show

data Arb = Empty | Node Int Arb Arb
   deriving Show

class ToFromArb a where
   toArb :: a -> Arb
   fromArb :: Arb -> a 

instance ToFromArb Point where 
   toArb (Pt []) = Empty 
   toArb (Pt (x:xs)) = Node x (toArb (Pt (filter (< x) xs)))  (toArb (Pt (filter (>= x) xs)))
   fromArb Empty = Pt [] 
   fromArb (Node x st dr) = let Pt l1 = fromArb st 
                                Pt l2 = fromArb dr
                            in Pt (l1 ++ [x] ++ l2)