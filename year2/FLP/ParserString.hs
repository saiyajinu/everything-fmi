import Data.List

parseString :: String -> String -> Either String String
parseString pattern input =
  if pattern `isInfixOf` input
    then Right pattern
    else Left "Pattern not found in input"

main = do
  let pattern = "Worlds"
  let input = "Hello, World!"
  case parseString pattern input of
    Left err -> putStrLn err
    Right str -> putStrLn str
