import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

file_path = "../counting_operations/results_with_comparisons.csv"
df = pd.read_csv(file_path)

df_time = df.melt(id_vars=["Size", "Type"],
                  value_vars=["InsertionSort_Time(ms)", "QuickSort_Time(ms)", "MergeSort_Time(ms)"],
                  var_name="Algorithm",
                  value_name="Time (ms)")

df_time["Algorithm"] = df_time["Algorithm"].str.replace("_Time\(ms\)", "", regex=True)

plt.figure(figsize=(10, 6))
sns.lineplot(data=df_time, x="Size", y="Time (ms)", hue="Algorithm", style="Type", markers=True, dashes=False)
plt.title("Sorting Time by Algorithm and Input Type")
plt.grid(True)
plt.tight_layout()
plt.savefig("time_comparison.png")
plt.show()

df_comp = df.melt(id_vars=["Size", "Type"],
                  value_vars=["InsertionSort_Comparisons", "QuickSort_Comparisons", "MergeSort_Comparisons"],
                  var_name="Algorithm",
                  value_name="Comparisons")

df_comp["Algorithm"] = df_comp["Algorithm"].str.replace("_Comparisons", "", regex=True)

plt.figure(figsize=(10, 6))
sns.lineplot(data=df_comp, x="Size", y="Comparisons", hue="Algorithm", style="Type", markers=True, dashes=False)
plt.title("Number of Comparisons by Algorithm and Input Type")
plt.grid(True)
plt.tight_layout()
plt.savefig("comparison_count.png")
plt.show()
