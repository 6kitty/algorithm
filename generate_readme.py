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
    """문제 디렉토리의 README.md → (tier, link)"""
    tier = link = None
    with open(path, encoding="utf-8") as f:
        text = f.read()

    # 첫째 줄 끝: /> Bronze V
    m = re.search(r"/>\s*((?:Bronze|Silver|Gold|Platinum|Diamond|Ruby)\s+[IV]+)", text)
    if m:
        tier = m.group(1)

    # [문제 링크](URL)
    m = re.search(r"\[문제 링크\]\((https?://[^\)]+)\)", text)
    if m:
        link = m.group(1)

    return tier, link


TIER_COLORS = {
    "Bronze": "#ad5600",
    "Silver": "#c0c0c0",
    "Gold": "#daa520",
    "Platinum": "#70c7ba",
    "Diamond": "#4fc3f7",
    "Ruby": "#e91e3c",
}

# 배지 위 텍스트 색 (밝은 배경 → 어두운 글자)
TIER_TEXT_COLORS = {
    "Bronze": "#fff",
    "Silver": "#444",
    "Gold": "#444",
    "Platinum": "#fff",
    "Diamond": "#fff",
    "Ruby": "#fff",
}


def generate_tier_chart(problems):
    """problems 리스트로부터 tier별 문제 수 수평 바 차트 SVG 생성"""
    # 정렬 순서 유지하면서 tier별 집계 (OrderedDict 대신 리스트로)
    seen = {}
    tier_entries = []  # (rank, tier, count)
    for rank, _num, _title, tier, _link in problems:
        if tier not in seen:
            seen[tier] = len(tier_entries)
            tier_entries.append([rank, tier, 0])
        tier_entries[seen[tier]][2] += 1

    if not tier_entries:
        return

    max_count = max(e[2] for e in tier_entries)

    # 레이아웃 상수
    PAD_L = 16
    PAD_R = 28
    PAD_T = 44      # 타이틀 아래
    PAD_B = 14
    LABEL_W = 82
    BAR_GAP = 10
    BAR_MAX_W = 180
    ROW_H = 30
    BAR_H = 16

    W = PAD_L + LABEL_W + BAR_GAP + BAR_MAX_W + BAR_GAP + PAD_R
    H = PAD_T + len(tier_entries) * ROW_H + PAD_B

    s = []
    s.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}">')
    s.append(f'  <rect width="{W}" height="{H}" rx="8" fill="#f6f8fa" stroke="#e1e4e8"/>')

    # 타이틀
    s.append(
        f'  <text x="{W / 2}" y="28" text-anchor="middle" '
        f'font-family="Segoe UI, sans-serif" font-size="14" font-weight="600" fill="#24292e">'
        f"Solved by Tier</text>"
    )

    bar_x = PAD_L + LABEL_W + BAR_GAP

    for i, (rank, tier, count) in enumerate(tier_entries):
        y = PAD_T + i * ROW_H
        bar_y = y + (ROW_H - BAR_H) // 2
        category = tier.split()[0]
        color = TIER_COLORS.get(category, "#ccc")
        text_color = TIER_TEXT_COLORS.get(category, "#333")

        # 배지 (tier 이름)
        s.append(f'  <rect x="{PAD_L}" y="{y + 4}" width="{LABEL_W}" height="22" rx="4" fill="{color}"/>')
        s.append(
            f'  <text x="{PAD_L + LABEL_W / 2}" y="{y + 19}" text-anchor="middle" '
            f'font-family="Segoe UI, sans-serif" font-size="11" font-weight="600" fill="{text_color}">'
            f"{tier}</text>"
        )

        # 바 배경 (트랙)
        s.append(f'  <rect x="{bar_x}" y="{bar_y}" width="{BAR_MAX_W}" height="{BAR_H}" rx="3" fill="#e1e4e8"/>')

        # 바 채움
        fill_w = max(4, int(count / max_count * BAR_MAX_W))
        s.append(f'  <rect x="{bar_x}" y="{bar_y}" width="{fill_w}" height="{BAR_H}" rx="3" fill="{color}"/>')

        # 문제 수 텍스트
        count_x = bar_x + BAR_MAX_W + BAR_GAP
        s.append(
            f'  <text x="{count_x}" y="{bar_y + 13}" '
            f'font-family="Segoe UI, sans-serif" font-size="13" font-weight="600" fill="#586069">'
            f"{count}</text>"
        )

    s.append("</svg>")

    with open("tier_stats.svg", "w", encoding="utf-8") as f:
        f.write("\n".join(s))


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

        tier, link = parse_readme(readme_path)
        rank = tier_to_rank(tier) if tier else 0
        problems.append((rank, num, title, tier or "Unrated", link or ""))

    # 정렬: 티어 내림차순, 같은 tier면 문제번호 오름차순
    problems.sort(key=lambda x: (-x[0], x[1]))

    # tier별 바 차트 SVG 생성
    generate_tier_chart(problems)

    # Markdown 테이블 생성
    lines = [
        "# Algorithm Solutions",
        "",
        f"Total: **{len(problems)}문제**",
        "",
        "![Tier Stats](tier_stats.svg)",
        "",
        "| 문제번호 | 문제 제목 | Tier | 문제 링크 |",
        "|:---:|:---|:---:|:---:|",
    ]

    for rank, num, title, tier, link in problems:
        icon = (
            f'<img src="https://static.solved.ac/tier_small/{rank}.svg" style="height:20px" /> '
            if rank
            else ""
        )
        link_cell = f"[BOJ]({link})" if link else "-"
        lines.append(f"| {num} | {title} | {icon}{tier} | {link_cell} |")

    lines.append("")  # trailing newline

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(lines))


if __name__ == "__main__":
    main()
