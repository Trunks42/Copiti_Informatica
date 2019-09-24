import time,random
rete=["host1","host2","host3","host4"]

def collisione(tempo):
    print("[+] e' avvenuta una collisione fra: "+ rete[1] +" e "+ rete[2])
    time.sleep(0.8)
    print("[+] " + rete[1] +" e "+ rete[2] + " stanno mandando il segnale di JAM")
    time.sleep(0.8)
    print("[+] Il tempo si attesa e di: "+str(tempo)+" millisecondi")
    time.sleep(tempo/500)

def main():
    tempo=1000
    flag=0
    while flag==0:
        n=random.randrange(0,4)
        random.shuffle(rete)
        print("[+] " + rete[0]+ " sta comunicando")
        time.sleep(0.8)
        if n==1:
            collisione(tempo)
            tempo+=1000
            flag=random.randrange(0,2)
        else:
            tempo=1000
    print("[+] Spegno la rete.")
    


if __name__ == "__main__":
    main()



