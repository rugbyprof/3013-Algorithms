import glob
from random import shuffle
from operator import itemgetter
import subprocess

path = './card_images/'

def read_cards(size='medium'):
    cards = glob.glob(path+size+'/*.gif')
    return cards

def base_vals(suit,rank):
    """ Repeated code block for two functions stuck here.
    """
    suit_value = {'s':0,'h':1,'d':2,'c':3}
    face_cards = {'a':1,'k':13,'q':12,'j':11}

    if rank in face_cards:
        rank = face_cards[rank]
    
    suit = suit_value[suit]
    rank = int(rank)

    return suit,rank

def get_tuple(**kwargs):
    """Just want the "base values" of the card to sort with
    """
    suit = kwargs.get('suit',None)
    rank = kwargs.get('rank',None)

    

    suit,rank = base_vals(suit,rank)
    print(f"rank={rank}")
    if rank == 1:
        rank = 14

    return suit,rank

def get_card(**kwargs):
    """Return a value used to pull the image from the deck.
    """
    suit = kwargs.get('suit',None)
    rank = kwargs.get('rank',None)

    suit,rank = base_vals(suit,rank)

    value = suit * 13 + rank 

    return value - 1

def get_card_2(card):
    rev_suit_value = ['s','h','d','c'] # stupid don't laugh

    suit = rev_suit_value[card[0]]
    rank = card[1]
    suit,rank = base_vals(suit,rank)

    value = suit * 13 + rank 

    return value - 1

def magick_me(**kwargs):
    hand = kwargs.get('hand',None)
    direction = kwargs.get('direction','+') # or '-' for stacked
    outname = kwargs.get('outname','combined.png')

    cmd = ['convert','+append']
    for h in hand:
        cmd.append(h)
    
    cmd.append(outname)

    process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    output, error = process.communicate()
    
    return output



if __name__=='__main__':
    #{'s':0,'h':1,'d':2,'c':3}
    #wanted_cards = ['kd','qd','10c','js','as','ac','3c','4d','8d']
    wanted_cards = ['2s','2h','2d','2c','3s','3h','3d','3c','4s','4h','4d','4c','5s','5h','5d','5c']
    wanted_tuples = []
    hand = []

    shuffle(wanted_cards)

    deck = read_cards(size='xsmall')
    deck = sorted(deck)

    #print(deck)

    for card in wanted_cards:
        rank = card[0:-1]
        suit = card[-1]
        c = get_card(rank=rank,suit=suit)
        wanted_tuples.append(get_tuple(rank=rank,suit=suit))
        hand.append(deck[c])

    # print("")
    # print(hand)
    # print("")
    # cmd = magick_me(hand=hand,outname="sorted_not_1.png")
    # print(cmd)

    # print("")
    # hand = sorted(hand)
    # print(hand)
    # print("")
    # cmd = magick_me(hand=hand,outname="sorted_1.png")
    # print(cmd)

    # print("")

    hand = []
    print(wanted_tuples)
    print(wanted_tuples)
    for card in wanted_tuples:
        c = get_card_2(card)
        hand.append(deck[c])
    print(hand)
    print("")
    cmd = magick_me(hand=hand,outname="a.png")
    print(cmd)
    print("")
    print("")

    hand = []
    print(wanted_tuples)
    wanted_tuples = sorted(wanted_tuples,key=itemgetter(1))
    print(wanted_tuples)
    for card in wanted_tuples:
        c = get_card_2(card)
        hand.append(deck[c])
    print(hand)
    print("")
    cmd = magick_me(hand=hand,outname="b.png")
    print(cmd)
    print("")
    print("")

    hand = []
    wanted_tuples = sorted(wanted_tuples,key=itemgetter(0))

    print(wanted_tuples)
    for card in wanted_tuples:
        c = get_card_2(card)
        hand.append(deck[c])
    print(hand)
    print("")
    cmd = magick_me(hand=hand,outname="c.png")
    print(cmd)


