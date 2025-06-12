import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
file_path = "../computing_running_time/sort_results.csv"
df = pd.read_csv(file_path)

df['Type'] = df['Type'].astype('category')

plt.figure(figsize=(10, 6))
sns.lineplot(data=df, x="Size", y="Time(ms)", hue="Algorithm", style="Type", markers=True, dashes=False)
plt.title("Sorting Time by Algorithm and Input Type")
plt.xlabel("Input Size")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.tight_layout()
plt.savefig("sort_time_graph.png")
plt.show()
