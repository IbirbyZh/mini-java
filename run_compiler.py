import subprocess
import argparse


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--executable')
    parser.add_argument('--input')
    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()
    with open(args.input) as input_stream:
        subprocess.call([args.executable], stdin=input_stream)