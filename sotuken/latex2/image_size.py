import os
from PIL import Image

def resize_images_for_latex(folder_path, text_width_mm, dpi):
    mm_to_pixels = dpi / 25.4  # 1インチ = 25.4mm
    text_width_pixels = text_width_mm * mm_to_pixels

    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp')):
                image_path = os.path.join(root, file)
                image = Image.open(image_path)
                original_width, original_height = image.size

                # 新しい画像の高さを計算（元の縦横比を保持）
                new_height_pixels = original_height * (text_width_pixels / original_width)

                # ピクセルからミリメートルに変換
                new_height_mm = new_height_pixels / mm_to_pixels

                # LaTeX形式で出力
                relative_image_path = os.path.relpath(image_path, folder_path)
                print(f"Image: {image_path}")
                print(f"\\includegraphics[width={text_width_mm}mm,height={new_height_mm:.2f}mm]{{./img/{relative_image_path}}}")
                print("-----")

# imgフォルダのパス
folder_path = './img'
latex_text_width_mm = 100  # LaTeXのテキスト領域の幅（mm単位）
dpi = 300  # 一般的な印刷のDPI

resize_images_for_latex(folder_path, latex_text_width_mm, dpi)
