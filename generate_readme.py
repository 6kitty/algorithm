import os
import re

# solved.ac 티어 SVG 번호 매핑
# SVG 번호 = TIER_BASE + LEVEL_NUM (정렬 키로서도 동일)
# Bronze V=1 ... Bronze I=5, Silver V=6 ... Silver I=10, Gold V=11 ...
TIER_BASE = {
    "Bronze": 0,
    "Silver": 5,
    "Gold": 10,
    "Platinum": 15,
    "Diamond": 20,
    "Ruby": 25,
}

LEVEL_NUM = {"V": 1, "IV": 2, "III": 3, "II": 4, "I": 5}


def tier_to_rank(tier_str):
    """'Silver II' → 9  (SVG 번호 = 정렬 키)"""
    parts = tier_str.strip().split()
    if len(parts) != 2:
        return 0
    return TIER_BASE.get(parts[0], 0) + LEVEL_NUM.get(parts[1], 0)


def parse_readme(path):
    """문제 디렉토리의 README.md → tier"""
    with open(path, encoding="utf-8") as f:
        text = f.read()

    # 첫째 줄 끝: /> Bronze V
    m = re.search(r"/>\s*((?:Bronze|Silver|Gold|Platinum|Diamond|Ruby)\s+[IV]+)", text)
    return m.group(1) if m else None


def main():
    problems = []

    for entry in os.listdir("."):
        if not os.path.isdir(entry) or "번: " not in entry:
            continue

        num_str, title = entry.split("번: ", 1)
        try:
            num = int(num_str)
        except ValueError:
            continue

        readme_path = os.path.join(entry, "README.md")
        if not os.path.isfile(readme_path):
            continue

        tier = parse_readme(readme_path)
        rank = tier_to_rank(tier) if tier else 0
        problems.append((rank, num, title, tier or "Unrated"))

    # 정렬: 티어 내림차순, 같은 tier면 문제번호 오름차순
    problems.sort(key=lambda x: (-x[0], x[1]))

    # Markdown 테이블 생성
    lines = [
        "# Algorithm Solutions",
        "",
        "| 문제번호 | 문제 제목 | Tier |",
        "|:---:|:---|:---:|",
    ]

    for rank, num, title, tier in problems:
        icon = (
            f'<img src="https://static.solved.ac/tier_small/{rank}.svg" style="height:20px" /> '
            if rank
            else ""
        )
        lines.append(f"| {num} | {title} | {icon}{tier} |")

    lines.append("")  # trailing newline

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(lines))


if __name__ == "__main__":
    main()
