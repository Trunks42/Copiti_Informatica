import time
import random
rete = ["host1", "host2", "host3", "host4"]
tempo = 1000


def collisione():
    print("[+] e' avvenuta una collisione fra: " + rete[1] + " e " + rete[2])
    time.sleep(0.8)
    print("[+] " + rete[1] + " e " + rete[2] +
          " stanno mandando il segnale di JAM")
    time.sleep(0.8)
    t1 = random.randrange(500, tempo, 50)
    t2 = random.randrange(500, tempo, 50)
    if t1 == t2:
        collisione()
    else:
        print("[+] Il tempo si attesa di " + rete[1] + "e: " +str(t1)+" millisecondi")
        print("[+] Il tempo si attesa di " + rete[2] + "e: " +str(t2)+" millisecondi")
        if t1<t2:
            time.sleep(t1/1000)
            print("[+] " + rete[1] + " sta comunicando")
            time.sleep((t2-t1)/1000)
            print("[+] " + rete[2] + " sta comunicando")
        else:
            time.sleep(t2/1000)
            print("[+] " + rete[2] + " sta comunicando")
            time.sleep((t1-t2)/1000)
            print("[+] " + rete[1] + " sta comunicando")



def main():
    while True:
        n = random.randrange(0, 4)
        random.shuffle(rete)
        if n != 1:
            print("[+] " + rete[0] + " sta comunicando")
            time.sleep(0.8)
        elif n == 1:
            collisione()


if __name__ == "__main__":
    main()
