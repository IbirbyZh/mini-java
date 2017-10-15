import subprocess
import argparse
import os


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--executable')
    parser.add_argument('--input')
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

    with open(args.input) as input_stream, open('output.txt', 'w') as output_stream:
        subprocess.call([args.executable], stdin=input_stream, stdout=output_stream)
    with open(os.devnull, "w") as nothing:
        subprocess.call(['dot', '-Tpng', '-O', 'output.txt'], stdout=nothing, stderr=nothing)
