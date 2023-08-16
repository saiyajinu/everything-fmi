getFromIntervalSel a b list = [x | x<-list, x>=a, x<=b]

getFromInterval a b list = do 
    x<-list 
    if a <= x && x <= b then return x else Nothing