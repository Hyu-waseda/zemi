import pykakasi

# pykakasiの初期化
kakasi = pykakasi.kakasi()
kakasi.setMode("H", "a")  # 平仮名をローマ字に
kakasi.setMode("K", "a")  # カタカナをローマ字に
kakasi.setMode("J", "a")  # 漢字をローマ字に
kakasi.setMode("r", "Hepburn")  # ヘボン式ローマ字
converter = kakasi.getConverter()

# 参考文献リスト
references = [
    "大向一輝 (2006). SNS の現在と展望...",
    "小川泰弘，福田ムフタル，外山勝彦 (2009). 日本語ーウイグル語翻訳掲示板システム...",
    # その他の参考文献を追加
]


