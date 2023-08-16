import Data.List
import System.IO


num9 = 9 :: Int
sqrtOf9 = sqrt (fromIntegral num9)


--Lists
primeNumbers = [3,5,7,11]
morePrimes = primeNumbers ++ [13,17,19,23,29]
favNums = 2 : 7 : 21 : 66 :[]
multList = [[3,5,7],[11,13,17]]
morePrimes2 = 2 : morePrimes
lenPrime = length morePrimes2
revPrime = reverse morePrimes2
isListEmpty = null morePrimes2
secondPrime = morePrimes2 !! 1
firstPrime = head morePrimes2
lastPrime = last morePrimes2
primeInit = init morePrimes2
first3Primes = take 3 morePrimes2
is7InList = 7 `elem` morePrimes2

newList = [2,3,5]
prodPrimes = product newList
many2s = take 10 (repeat 2)

listTimes2 = [x * 2 | x <- [1..28], x * 3 <= 50]
divisBy9N13 = [x | x <- [1..500], x `mod` 13 == 0, x `mod` 9 == 0]

sortedList = sort [9,5,8,2,5,0,4]
sumOfLists = zipWith (+) [1,2,3,4] [6,7,8,9]
listBiggerThan5 = filter (>5) morePrimes
evensUpTo20 = takeWhile (<= 20) [2,4..]

multOfList = foldl (*) 1 [2,3,4,5]

--Lists comprehension
pow3List = [3^n | n <- [1..10]]
multTable = [[x * y | y <- [1..10]] | x <- [1..10]]

--Tuples
randTuple = (1, "Random Tuple")
bobSmith = ("Bob Smith", 52)
bobsName = fst bobSmith
bobsAge = snd bobSmith
names = ["Bob", "Mary", "Tom"]
addresses = ["123 M", "234 N", "345 B"]
namesNAddress = zip names addresses

{-
--main ~ ghc --make haskell-tut ~ haskell-tut.exe ~
main = do
   putStrLn "What's your name?"
   name <- getLine
   putStrLn ("Hello " ++ name)
-}

addMe :: Int -> Int -> Int
-- funcName param1 param2 = operations (returned value)
addMe x y = x + y 

sumMe x y = x + y

addTuples :: (Int, Int) -> (Int, Int) -> (Int, Int)
addTuples (x, y) (x2, y2) = (x + x2, y + y2)

whatAge :: Int -> String
whatAge 16 = "You can drive"
whatAge 18 = "You can vote"
whatAge 21 = "You're an adult"
whatAge x = "Idk"

--recursive
factorial :: Int -> Int

factorial 0 = 1
factorial n = n * factorial (n - 1)

prodFact n = product [1..n]

isOdd :: Int -> Bool

isOdd n
   | n `mod` 2 == 0 = False
   | otherwise = True
   
isEven n = n `mod` 2 == 0


whatGrade :: Int -> String

whatGrade age
   | (age >= 5) && (age <= 6) = "Kindergarten"
   | (age > 6) && (age <= 10) = "School"
   | (age > 10) && (age <= 14) = "Middle School"
   | (age > 14) && (age <= 18) = "High School"
   | otherwise = "Go to college"
   
batAvgRating :: Double -> Double -> String
batAvgRating hits atBats
   | avg <= 0.200 = "Terrible bat"
   | avg <= 0.250 = "Average bat"
   | otherwise = "Good  bat"
   where avg = hits / atBats
   
--access list items
getListItems :: [Int] -> String

getListItems [] = "empty"
getListItems (x:[]) = "Your list starts with" ++ show x
getListItems (x:y:[]) = "Your list contains" ++ show x ++ "and" ++ show y
getListItems (x:xs) = "The 1st item is " ++ show x ++ "and the rest are " ++ show xs

getFirstItem :: String -> String
getFirstItem [] = "Empty String"
getFirstItem all@(x:xs) = "The first letter in " ++ all ++ " is " ++ [x]


times4 :: Int -> Int
times4 x = x * 4

listTimes4 = map times4 [1,2,3,4]

multBy4 :: [Int] -> [Int]
multBy4 [] = []
multBy4 (x:xs) = times4 x : multBy4 xs

areStringsEq :: [Char] -> [Char] -> Bool
areStringsEq [] [] = True
areStringsEq (x:xs) (y:ys) = x == y && areStringsEq xs ys 
areStringsEq _ _ = False

doMult :: (Int -> Int) -> Int 
doMult func = func 3

num3Times4 = doMult times4 

getAddFunc :: Int -> (Int -> Int)
getAddFunc x y = x + y
adds3 = getAddFunc 3 
fourPlus3 = adds3 4

threePlusList = map adds3 [1,2,3,4,5]

--lambda

dbl1To10 = map (\x -> x * 2) [1..10]

--if

doubleEvenNumber y =
   if (y `mod` 2 /= 0)
    then y
    else y*2

--case

getClass :: Int -> String
getClass n = case n of 
   5 -> "small"
   6-> "med"
   _-> "high"
   
--modules
{-
module SampFunctions (getClass, doubleEvenNumber) where


import SampFunctions
-}
--types

data BaseballPlayer = Pitcher | Catcher | Infielder | Outfield deriving Show

barryBonds :: BaseballPlayer -> Bool
barryBonds Outfield = True
barryInOF = print(barryBonds Outfield)

data Customer = Customer String String Double
   deriving Show
   
tomSmith :: Customer
tomSmith = Customer "Tom Smith" "123 Main" 20.50
getBalance :: Customer -> Double
getBalance (Customer _ _ b) = b

data RPS = Rock | Paper | Scissors
shoot :: RPS -> RPS -> String
shoot Paper Rock = "Paper Beats Rock"
shoot _ _="paper rock only"

data Shape = Circle Float Float Float | Rectangle Float Float Float Float
   deriving Show 
   
area :: Shape -> Float
area (Circle _ _ r) = pi * r ^ 2
area (Rectangle x y x2 y2) = (abs $ x2-x) * (abs $ y2-y)
circle :: Shape
circle = Circle 1 1 1

sumValue = putStrLn (show (1+2))
sumValue2 = putStrLn . show $ 1 + 2

areaOfCircle = area (Circle 50 60 20)
areaOfRect = area $ Rectangle 10 10 100 100

--type classes

data Employee = Employee { name:: String,
   position :: String,
   idNum :: Int
   } deriving (Eq, Show)
   
samSmith = Employee {name = "Sam", position = "Manager", idNum = 1001}
maxSmith = Employee {name = "Max", position = "Sales", idNum = 1002}

isSamMax = samSmith == maxSmith

samSmithData = show samSmith 


data ShirtSize = S | M | L 
instance Eq ShirtSize where
   S == S = True
   M == M = True
   L == L = True
   _ == _ = False
   
instance Show ShirtSize where
   show S = "Small"
   show M = "Medium"
   show L = "Large"
   
smallAvail = S `elem` [M,L]
theSize = show S


class MyEq a where
   areEqual :: a -> a -> Bool
   
instance MyEq ShirtSize where
   areEqual S S = True
   areEqual M M = True
   areEqual L L = True
   areEqual _ _ = False
   
newSize = areEqual M S

-- IO
sayHello = do
   putStrLn "What is your name"
   name <- getLine
   putStrLn $ "Hello " ++ name
   
writeToFile = do
   theFile <- openFile "test.txt" WriteMode
   hPutStrLn theFile ("Random line of text")
   hClose theFile
   
readFromFile = do
   theFile2 <- openFile "test.txt" ReadMode
   contents <- hGetContents theFile2
   putStr contents
   hClose theFile2
   
-- fibonacci

fib = 1 : 1 : [a + b | (a, b) <- zip fib (tail fib)]

fib5 = fib !! 5

testt = 3 : 2 : [ a | a <- tail testt]