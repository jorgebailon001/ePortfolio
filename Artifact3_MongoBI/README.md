# 📊 Artifact 3: MongoDB and Power BI Integration

This artifact showcases the integration of **NoSQL data (MongoDB)** with **Power BI** to perform data-driven analysis and visualization. Originally, the analysis was based on insurance claims data (Excel format). For the capstone enhancement, global **airline, airport, and route datasets** were ingested into MongoDB, cleaned, and visualized in Power BI to provide strategic insights for a Nigerian airline planning international expansion.

---

## ✨ Features & Enhancements

| Feature                            | Description                                                                 |
|------------------------------------|-----------------------------------------------------------------------------|
| ✅ Original Excel dashboard         | Power BI report built from insurance claim data using Excel source         |
| 🌍 MongoDB Integration              | Loaded airline, airport, and route datasets into MongoDB                   |
| 📈 Power BI + NoSQL Visualization  | Connected Power BI to MongoDB with custom queries                          |
| 🔄 Real-world application           | Supports aviation route planning and international market analysis         |
| 📸 Screenshot archive               | Includes visuals of key insights and dashboards generated                  |

---

## 🗂️ Project Structure

```plaintext
Artifact3_MongoBI/
├── README.md                           ← Project overview and enhancement summary
├── Original/
│   ├── DAT 310 Insurance Data.xlsx     ← Original dataset used for Excel analysis
│   └── insurance_data.pbix (linked)    ← Hosted externally on OneDrive
├── Enhanced/
│   ├── airlines_utf8.csv
│   ├── airports_utf8.csv
│   ├── routes.csv
│   ├── airline_status_distribution.csv
│   ├── top_10_airlines_by_route_count.csv
│   ├── top_10_airports_by_country.csv
│   └── airport_dashboard.pbix (linked) ← Hosted externally due to size limit
├── Screenshots/
│   ├── Airline_Data.png
│   ├── Airport_Data.png
│   ├── Airport_Chart.png
│   ├── Airport_Pie_Chart.png
│   ├── Airport_Routes.png
│   ├── Routes_Data.png
│   ├── InsuranceData.png
│   └── Insurance_Data_2.png

```

## 🔗 Enhanced Power BI Dashboard

🔍 **View the Enhanced Dashboard:**  
[📂 airport_dashboard.pbix – View via OneDrive](https://1drv.ms/u/c/c7d4b73524dc22bd/EX35aPyhtwtMsA1OSL2cqgMBuLdhZcWCpVYl9otxVbcQCw?e=45Evfs)  

🔍 **View the Original Dashboard:**  
[📂 insurance_data.pbix – View via OneDrive](https://1drv.ms/u/c/c7d4b73524dc22bd/EfvyX4O19u9OuOeMuBXLLiUBM_caU0pQJ-4Pf8MwKkVNUg?e=trbZlE)

🔍 **View the Original Dashboard:**  
📄 [DAT 310 Insurance Data.xlsx – View via OneDrive](https://1drv.ms/x/c/c7d4b73524dc22bd/EcR62cvMbz9Mtn33OsUSDEoBSloatkCZcKKoYic9Scju5Q?e=i3LqPp)

Use the links above to download or explore the Power BI reports showcasing MongoDB-enhanced airline data and the original Excel-based insurance analysis.
---

## 🚀 How to Run (Optional)

To recreate or extend the analysis on your machine:

1. **Import Data to MongoDB**
   - Use MongoDB Compass or `mongoimport` to load `.csv` files from the `Enhanced/` folder:
     - `airlines_utf8.csv`
     - `airports_utf8.csv`
     - `routes.csv`
     - and others…

2. **Connect Power BI to MongoDB**
   - Use either:
     - A MongoDB BI Connector (for direct querying)
     - Exported `.csv` or `.json` data as an import source

3. **Rebuild or Explore Visuals**
   - Use the included `.pbix` file or replicate charts as shown in the `Screenshots/` folder:
     - Bar chart (Airports by Country)
     - Pie chart (Airline Route Distribution)
     - Table views (Airline/Airport/Route data)

---

## 🧠 Learning Outcome

This enhancement demonstrates the following skills:

✅ End-to-end pipeline: **CSV → MongoDB → Power BI**  
✅ Use of **NoSQL data modeling** and **aggregation queries**  
✅ Visual storytelling with **interactive dashboards**  
✅ Application of academic learning to **real-world aviation strategy**
