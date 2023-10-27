_teste2() {
  dynamic s = <String, dynamic>{
    'nivel-1': {'nivel-2': 2},
    'nivel-1_2': {'nivel-2': 2},
    'nivel-1_4': {
      'nivel-2': {"tess": 9}
    }
  };
  if (s['nivel-1_4'] is Map && s['nivel-1_4']['nivel-s2'] is Map) {
    print(s['nivel-1_4']['nivel-2']);
  }
  print('nivel-1_4'.toString());
}

Future<void> _farinha(Duration s) async {
  var timeWhile = true;
  Future.delayed(s, () => timeWhile = false);
  int i = 0;
  do {
    await Future.delayed(const Duration(milliseconds: 200));
    print(++i);
  } while (timeWhile);
  return;
}

int _testeMuitoAleatorio() {
  try {
    print("Esse é um print estranho");
    return 0;
    print("Esse é um print estranho pos return");
  } finally {
    print("Esse é um print estranho no fynally");
    return 9;
  }
}

Map<String, int> mapValuesChar = {
  'I': 1,
  'IV': 4,
  'V': 5,
  'IX': 9,
  'X': 10,
  'XV': 40,
  'L': 50,
  'XC': 90,
  'C': 100,
  'CD': 400,
  'D': 500,
  'CM': 900,
  'M': 1000,
};

List<String> validToSub = ['I', 'X', 'C'];

calcRoman(String nomanNumber) {
  var listChar = nomanNumber.toUpperCase().split('');

  if (listChar.any((element) => !mapValuesChar.keys.contains(element))) {
    return "Letrá não mapeada";
  }

  int Soma = 0;
  String lastChar = '';
  int countChar = 0;

  for (final String char in listChar) {
    int currentNum = mapValuesChar[char]!;

    if (lastChar == char) {
      countChar++;
    } else {
      countChar = 0;
    }
    if (countChar >= 3) {
      return "Quantidade de letras em sequência não é valida";
    }
    int lastNumb = mapValuesChar[lastChar] ?? 0;

    if (lastNumb != 0 && lastNumb < currentNum) {
      if (mapValuesChar[lastChar + char] == null) return 'Número inválidoss';
      Soma += mapValuesChar[lastChar + char]! - lastNumb;
    } else {
      Soma += currentNum;
      lastNumb = currentNum;
    }

    lastChar = char;
  }

  return Soma.toString();
}

void main() async {
  print(calcRoman("MDCCLXXVI"));
}
