# hitachi-ac-remote
日立エアコンを設定時刻に起動するプロトタイプ

## IRremote
- 設定時刻（=6:00）に日立エアコンを起動する
  - WiFi接続してntpサーバと時刻を同期
  - 6時になったら赤外線エミッタから、PowerOnシグナルを出力
  - シグナルは、下記のIRremote_analyzerから取得

## IRremote_analyzer
- 赤外線リモコンのシグナルを解読する
  - 日立はプロトコルが意味不明
  - 家庭リモコンから、レシーバーに赤外線を当てて直接的に解読する

## 使用したもの
### ハードウェア
- [ESPr® Developer 32](https://www.switch-science.com/products/3210)
- [GROVE - 赤外線発信器](https://www.switch-science.com/products/885)
- [GROVE - 赤外線受信器](https://www.switch-science.com/products/910)
- [ESPr® Developer用GROVEシールド](https://www.switch-science.com/products/2811?variant=42381942751430)

## Arduinoライブラリ
- https://github.com/Arduino-IRremote/Arduino-IRremote

## 参考資料
- https://hawksnowlog.blogspot.com/2017/01/control-infrared-with-arduino.html#google_vignette
- http://elm-chan.org/docs/ir_format.html