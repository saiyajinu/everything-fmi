f1 :: String -> String -> String
f1 [] _ = ""
f1 _ [] = ""
f1 (c1:str1) (c2:str2)
    | c1 == c2 = c1 : f1 str1 str2
    | otherwise = ""


f2 :: [Int] -> [Int] -> Int
f2 [] [] = 0
f2 (xi:str1) (yi:str2)
   |length str1 /= length str2 = error "Input lists must have same length"
   | otherwise = (xi^2)*(yi^2) + f2 str1 str2



data PairInt = P Int Int deriving Show
data MyList = L [PairInt] deriving Show
data Exp = I Int | Add Exp Exp | Mul Exp Exp deriving Show
class MyClass m where
 toExp :: m -> Exp

instance MyClass MyList where
    toExp (L []) = I 1
    toExp (L ((P e1 e2):xs)) = Mul (Add (I e1) (I e2)) (toExp (L xs))

