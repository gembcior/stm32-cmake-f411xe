import argparse
from pathlib import Path
import subprocess
from typing import List


def find_input_files() -> List[Path]:
    gcov_files = []
    cwd = Path().cwd()
    for item in cwd.glob("**/*.gcda"):
        gcov_files.append(item)
    for item in cwd.glob("**/*.gcno"):
        gcov_files.append(item)
    result = []
    for item in gcov_files:
        item = item.with_suffix('.o')
        if item not in result:
            result.append(item)
    return result


def run_gcov(input_files: List[Path], output: Path) -> None:
    for item in input_files:
        cmd = ['gcov', f"{item}"]
        subprocess.run(cmd, cwd=output, check=True, capture_output=True)


def main() -> None:
    description = "Gather gcov coverage report."
    parser = argparse.ArgumentParser(description=description)

    parser.add_argument("output", help="Output directory path.")

    args = parser.parse_args()

    input_files = find_input_files()

    output = Path(args.output).expanduser().resolve()
    output.mkdir(exist_ok=True)

    run_gcov(input_files, output)


if __name__ == "__main__":
    main()
