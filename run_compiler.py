import subprocess
import argparse
import os
import sys


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--executable')
    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()
    try:
        with open(os.devnull, "w") as nothing:
            subprocess.check_call(
                [
                    '/Applications/CLion.app/Contents/bin/cmake/bin/cmake',
                    '--build', '/Users/ibirby/Documents/mini-java/cmake-build-debug',
                    '--target', 'all',
                    '--', '-j', '2'
                ],
                stdout=nothing,
                stderr=nothing
            )
    except subprocess.CalledProcessError:
        print 'Build Failed'
        raise
    for directory in ['Samples', 'BadSamples']:
        for filename in os.listdir(directory):
            print filename
            with open(os.path.join(directory, filename)) as input_stream:
                subprocess.call([args.executable], stdin=input_stream, stdout=sys.stdout, stderr=sys.stderr)
            print '==' * 30
